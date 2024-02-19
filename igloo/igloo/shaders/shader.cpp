#include "igloo/shaders/shader.h"
#include <type_traits>
#include <string>
#include <fstream>
#include <iterator>

namespace gl
{
  namespace detail
  {
    // [[nodiscard]] constexpr auto gl_cast(shader_type s)
    // {
    //   return static_cast<std::underlying_type_t<shader_type>>(s);
    // }

    void compile_shader_source(const GLuint shader_id, const std::string &code)
    {
      const auto c_code{code.c_str()};
      glShaderSource(shader_id, 1, &c_code, nullptr);
      glCompileShader(shader_id);
      GLint is_compiled{0};
      glGetShaderiv(shader_id, GL_COMPILE_STATUS, &is_compiled);
      // TODO Change this to a custom exception class like shader_error.
      require<std::runtime_error>(is_compiled == GL_TRUE);
    }
  }

  shader load_shader_from_file(const shader_type s, const std::string_view filepath)
  {
    std::ifstream shader_file{filepath.data()};
    require<std::runtime_error>(static_cast<bool>(shader_file));
    const std::string shader_code{
        std::istreambuf_iterator{shader_file}, std::istreambuf_iterator<char>{}};
    return shader(s, shader_code);
  }

  // shader::shader(const shader_type s) : m_id{glCreateShader(detail::gl_cast(s))}
  // {
  // }

  // vertex_shader::vertex_shader(const std::string& code) : shader{shader_type::vertex} {
  //   try {
  //     detail::compile_shader_source(id(), code);
  //   } catch (...) {
  //     glDeleteShader(id());
  //     throw;
  //   }
  // }
}