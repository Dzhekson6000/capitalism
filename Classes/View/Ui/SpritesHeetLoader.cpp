#include "SpritesHeetLoader.h"
#include <tinyxml2/tinyxml2.h>

SpritesHeetLoader *const SpritesHeetLoader::getInstance() noexcept
{
    static SpritesHeetLoader instance;
    return &instance;
}

SpritesHeetLoader::SpritesHeetLoader()
{
    filesystem::path path_frames = Constants::dir_frames_info;

    for (auto item : path_frames)
    {
        if (item.has_filename() && item.extension() == Constants::xml_format)
        {
            loadImage(item);
        }
    }
}

SpritesHeetLoader::~SpritesHeetLoader() noexcept
{
    for (auto &[key, value] : images)
    {
        value->release();
    }
}

void SpritesHeetLoader::loadImage(const filesystem::path &file_name)
{
    namespace xml = tinyxml2;

    xml::XMLDocument document;
    if (document.LoadFile(file_name.filename().c_str()))
    {
        return;
    }

    if (auto const texture_atlas = document.FirstChild())
    {
        while (xml::XMLElement *element = texture_atlas->NextSiblingElement("SubTexture"))
        {
            int width, height;
            std::string_view name = element->Attribute("name");
            width = element->IntAttribute("width");
            height = element->IntAttribute("height");

            std::string file_path;
            file_path.reserve(name.size() + Constants::dir_frames.size());
            file_path.append(Constants::dir_frames).append(name);

            images[std::string(name)] = cc::SpriteFrame::create(std::move(file_path), cc::Rect(0, 0, width, height));
        }
    }
}
