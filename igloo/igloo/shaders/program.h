#ifndef IGLOO_PROGRAM_H
#define IGLOO_PROGRAM_H

#include "igloo/shaders.h"
#include <GL/glew.h>
#include <variant>
#include <vector>

namespace gl
{
  namespace detail
  {
    [[nodiscard]] auto getLinkError(const GLuint program_id)
    {
      GLsizei log_length{0};
      glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &log_length);
      std::string log(log_length, '\0');
      glGetProgramInfoLog(program_id, log_length, &log_length, log.data());
      return log;
    }

    template <typename shader_list>
    void link_program(const GLuint program_id, const shader_list &shaders)
    {
      for (const auto &s : shaders)
      {
        glAttachShader(program_id, s.id());
      }
      glLinkProgram(program_id);
      GLint is_linked{GL_FALSE};
      glGetProgramiv(program_id, GL_LINK_STATUS, &is_linked);

      if (is_linked != GL_TRUE)
      {
        GLsizei log_length{0};
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &log_length);
        std::string log(log_length, '\0');
        glGetProgramInfoLog(program_id, log_length, &log_length, log.data());
      }
      // require<std::runtime_error>(is_linked == GL_TRUE, [program_id]()
      //                             { return getLinkError(program_id); });
    }
  }

  class program
  {
  public:
    template <typename shader_list>
    program(const shader_list &shaders)
        : m_id{glCreateProgram()}
    {
      require<std::runtime_error>(m_id > 0, "An error occurred creating the shader program.");
      try
      {
        detail::link_program(m_id, shaders);
      }
      catch (...)
      {
        glDeleteProgram(m_id);
        throw;
      }
    }
    ~program() { glDeleteProgram(m_id); }
    program(const program &) = delete;
    program(program &&) = default;
    program &operator=(const program &) = delete;
    program &operator=(program &&) = default;

    [[nodiscard]] auto id() const noexcept { return m_id; }

  private:
    GLuint m_id;
  };

  struct shader_file
  {
    std::string filepath;
    shader_type s_type;
  };

  template <typename shader_list>
  program load_program_from_files(const shader_list &shader_files)
  {
    std::vector<shader> shaders;
    for (const shader_file &file : shader_files)
    {
      shaders.emplace_back(load_shader_from_file(file.s_type, file.filepath));
    }
    return program{shaders};
  }

  void use_program(const program &p)
  {
    glUseProgram(p.id());
  }
}

#endif
