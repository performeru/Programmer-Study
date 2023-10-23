#pragma once
#include "D2DFramework.h"
#include "Actor.h"
#include <memory>

class ActorExample : public D2DFramework
{
	std::unique_ptr<Actor> mspBackground;
	std::unique_ptr<Actor> mspBug;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title=L"ActorExample",
		UINT width = 1024, UINT height = 768) override;
	virtual void Release() override;
	virtual void Render() override;
};
