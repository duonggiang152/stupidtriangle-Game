#pragma once
#include <string>
#include <glm/glm.hpp>
#include <unordered_map>
namespace Hazel {
	class Shader
	{
	public:
		// sets uniform shader
		virtual void SetFloat3(const std::string &name, const glm::vec3 &value) = 0;
		virtual void SetFloat4(const std::string &name, const glm::vec4 &value) = 0;
		virtual void SetMat4(const std::string &name, const glm::mat4 &value) = 0;
		virtual void SetInt(const std::string& name, const int &value) = 0;
		virtual void SetFloat(const std::string& name, const float& value) = 0;

		virtual std::string GetName() const = 0;
		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;
		static Ref<Shader> Create(const std::string &name, std::string& vertexShader, std::string& fragmentShader);
		static Ref<Shader> Create(std::string& filepath);
	};
	class ShaderLibrary
	{
	public:
		
		void Add(const Ref<Shader>& shader);
		void Add(const std::string name, const Ref<Shader>& shader);
		Ref<Shader> Load(std::string& filepath);
		Ref<Shader> Load(const std::string& name, std::string& filepath);
		Ref<Shader> Load(const std::string& name, std::string& vertexshader, std::string& fragmentShader);

		Ref<Shader> Get(const std::string& name);
	private:
		std::unordered_map<std::string, Ref<Shader> > m_Shaders;
	};
}