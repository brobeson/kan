#ifndef IGLOO_SHADER_H
#define IGLOO_SHADER_H

#include <GL/glew.h>
#include <string>
#include <stdexcept>

namespace gl
{
  // template <typename exc>
  // constexpr void require(const bool condition)
  // {
  //   require<exc>(condition, "");
  //   // if (!condition)
  //   // {
  //   //   throw exc{""};
  //   // }
  // }

  // template <typename exc, typename callback>
  // constexpr void require(const bool condition, const callback& message)
  // {
  //   // Don't call require(condition, message());
  //   // That will invoke the message callback regardless of the condition state.
  //   if (!condition)
  //   {
  //     auto msg{message()};
  //     throw exc{msg};
  //   }
  // }

  template <typename exc>
  constexpr void require(const bool condition, const std::string& message = "") {
    if (!condition) {
      throw exc{message};
    }
  }

  enum class shader_type : GLuint
  {
    fragment = GL_FRAGMENT_SHADER,
    vertex = GL_VERTEX_SHADER
  };

  namespace detail
  {
    [[nodiscard]] constexpr auto gl_cast(shader_type s)
    {
      return static_cast<std::underlying_type_t<shader_type>>(s);
    }

    void compile_shader_source(const GLuint shader_id, const std::string &code);
  }

  class shader
  {
  public:
    shader(const shader_type s, const std::string &code)
        : m_id{glCreateShader(detail::gl_cast(s))}
    {
      try
      {
        detail::compile_shader_source(m_id, code);
      }
      catch (...)
      {
        glDeleteShader(m_id);
        throw;
      }
    }

    ~shader()
    {
      glDeleteShader(m_id);
    }

    [[nodiscard]] auto id() const noexcept { return m_id; }

  private:
    GLuint m_id;
  };

  shader load_shader_from_file(const shader_type s, const std::string_view filepath);

  // using vertex_shader = full_shader<shader_type::vertex>;

  // class shader
  // {
  // protected:
  //   shader(const shader_type s);
  //   [[nodiscard]] auto id() const noexcept { return m_id; }

  // private:
  //   GLuint m_id;
  // };

  // class vertex_shader final : public shader
  // {
  //   explicit vertex_shader(const std::string &code);
  // };
}

#endif
