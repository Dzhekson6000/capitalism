#pragma once

#include <cocos/2d/CCSpriteFrame.h>
#include <memory>

#include "cocos2d.h"

#if __has_include(<filesystem>)
	#include <filesystem>
namespace filesystem = std::filesystem;
#elif __has_include(<experimental/filesystem>)
	#include <experimental/filesystem>
namespace filesystem = std::experimental::filesystem;
#else
//#error "std::filesystem not found"
#endif

using Images = std::map<std::string, cocos2d::SpriteFrame*>;

class LoaderSpriteSheets final
{
public:
	static LoaderSpriteSheets* const GetInstance() noexcept;

private:
	LoaderSpriteSheets();
	
	~LoaderSpriteSheets() noexcept;
	
	cocos2d::SpriteFrameCache* images;
	
	void _loadImage(const std::string &file_name);
	
	const std::string dir_frames;
	const std::string xml_format;
};
