#pragma once

#include <cocos/2d/CCSpriteFrame.h>
#include <memory>

#if __has_include(<filesystem>)
    #include <filesystem>
    namespace filesystem = std::filesystem;
#elif __has_include(<experimental/filesystem>)
    #include <experimental/filesystem>
    namespace filesystem = std::experimental::filesystem;
#else
    #error "std::filesystem not found"
#endif

using std::string_view_literals::operator ""sv;
namespace cc = cocos2d;
using Images = std::map<std::string, cc::SpriteFrame *>;

class SpritesHeetLoader final
{
public:
    static SpritesHeetLoader *const getInstance() noexcept;

    inline cc::SpriteFrame *getImage(const std::string &name)
    {
        return images[name];
    }

private:
    SpritesHeetLoader();

    ~SpritesHeetLoader() noexcept;

    Images images;

    void loadImage(const filesystem::path &file_name);

    struct Constants
    {
        static constexpr auto dir_frames_info = "./Resources/ui/Spritesheet/"sv;
        static constexpr auto dir_frames = "./Resources/ui/PNG/"sv;
        static constexpr auto xml_format = "xml"sv;
    };
};
