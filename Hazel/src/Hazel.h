#pragma once
//For use by hazel application
#include "Hazel/Application.h"
#include "Hazel/Log.h"
#include "Hazel/LayerStack.h"
#include "Hazel/ImGui/ImGuiLayer.h"
#include "Hazel/Input.h"
#include "MouseButtonCode.h"
#include "Keycode.h"
#include "Hazel/Core/Time.h"
#include "Hazel/Core/TimeStep.h"
//----- Hazel event ------ 

#include "Hazel/Events/Event.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"

//-----Hazel renderer-----
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Renderer/Renderer2D.h"
#include "Hazel/Renderer/RendererAPI.h"
#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/GraphicsContext.h"
#include "Hazel/Renderer/VertexArray.h"
#include "Hazel/Renderer/RenderCommand.h"
#include "Hazel/Renderer/OrthographicCameracontroller.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/Texture.h"
//----------------------------
#include "glm/gtc/matrix_transform.hpp"