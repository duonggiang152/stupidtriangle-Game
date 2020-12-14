#include "hzpch.h"

#include "Shader.h"
#include "RendererAPI.h"
#include "platform/OpenGL/OpenGLShader.h"
namespace Hazel {
	Ref<Shader> Shader::Create(const std::string &name,std::string& vertexShader, std::string& fragmentShader)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI:: NoneAPI");
		case RendererAPI::API::OpenGL: return std::make_shared<OpenGLShader>(name,vertexShader, fragmentShader);
		}
		return nullptr;

	}
	Ref<Shader> Shader::Create(std::string& filepath)
	{
		switch (RendererAPI::GetAPI())
		{
		case RendererAPI::API::None: HZ_CORE_ASSERT(false, "RendererAPI:: NoneAPI");
		case RendererAPI::API::OpenGL: return std::make_shared <OpenGLShader>(filepath);
		}
		return nullptr;
	}
	void ShaderLibrary::Add(const Ref<Shader>& shader)
	{
		auto name = shader->GetName();
		HZ_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end(), "Shader already exist");
		m_Shaders[name] = shader;
	}
	void ShaderLibrary::Add(const std::string name, const Ref<Shader>& shader)
	{
		HZ_CORE_ASSERT(m_Shaders.find(name) == m_Shaders.end(), "Shader already exist");
		m_Shaders[name] = shader;
	}
	Ref<Shader> ShaderLibrary::Load(std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(shader);
		return shader;
	}
	Ref<Shader> ShaderLibrary::Load(const std::string& name, std::string& filepath)
	{
		auto shader = Shader::Create(filepath);
		Add(name, shader);
		return shader;
	}
	Ref<Shader> ShaderLibrary::Load(const std::string& name, std::string& vertexshader, std::string& fragmentShader)
	{
		auto shader = Shader::Create(name,vertexshader, fragmentShader);
		Add(name, shader);
		return shader;
	}
	Ref<Shader> ShaderLibrary::Get(const std::string& name)
	{
		return m_Shaders[name];
	}
}