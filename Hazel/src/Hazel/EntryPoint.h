#pragma once
#ifdef HZ_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Hazel::Log::Init();
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif // HZ_PLATFORM_WINDOWS
