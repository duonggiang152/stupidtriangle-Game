#pragma once
#include "Hazel/Renderer/Shader.h"

#include <string>
#include <glm/glm.hpp>
typedef unsigned int GLenum;
namespace Hazel {
	class OpenGLShader :public Shader
	{
	public:
		OpenGLShader(const std::string& filepath);

		OpenGLShader(const std::string &name,const std::string& vertexSource, const std::string& fragmentSource);
		~OpenGLShader();
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) override;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) override;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) override;
		virtual void SetInt(const std::string& name, const int &value) override;
		virtual void SetFloat(const std::string& name, const float& value) override;

		virtual std::string GetName() const override { return m_Name; }
		virtual void Bind() const override;
		virtual void UnBind() const override;
		void UpLoadUniformFloat3(const std::string& name, const glm::vec3& value);
		void UpLoadUniformInt(const std::string& name, int value);
		void UpLoadUniformFloat4(const std::string& name, const glm::vec4& value);
		void UpLoadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		std::string ReadFile(const std::string& filepath);
		std::unordered_map<GLenum, std::string> preprocess(const std::string& source);
		void compile(const std::unordered_map<GLenum, std::string>& ShaderSource);
	private:
		uint32_t m_RendererID;
		std::string m_Name;
	};
	
}