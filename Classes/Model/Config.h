#ifndef CAPITALISM_CONFIG_H
#define CAPITALISM_CONFIG_H

class Config
{
public:
	static constexpr float TILE_SIZE = 23.0; ///< размер тайла
	static constexpr int SENSITIVITY_SCROLL = 20; ///< чувствительность скролла
	static constexpr int AREA_MOBILITY = 5; ///< область мобильности
	
	Config();
	~Config();
};


#endif //CAPITALISM_CONFIG_H
