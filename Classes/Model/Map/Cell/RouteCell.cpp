#include "RouteCell.h"
#include "Model/Map/Camera.h"

int RouteCell::getFrame()
{
	int frame = getBitMask();
	auto spriteFrame = getSpriteFrame();

	switch (frame)
	{
        case 4:
        case 8:
        case 12:
            spriteFrame->setFlippedX(true);
		case 1:
		case 2:
		case 3:
			frame = 1;
			break;

        case 9:
            spriteFrame->setFlippedX(true);
            spriteFrame->setFlippedY(true);
		case 6:
			frame = 3;
			break;

        case 10:
            spriteFrame->setFlippedX(true);
            spriteFrame->setFlippedY(true);
		case 5:
			frame = 4;
			break;

        case 7: // Y
		case 11: // X
		case 13: // X и Y
		case 14: //default
            switch (frame)
            {
                case 7:
                    spriteFrame->setFlippedY(true);
                    break;

                case 11:
                    spriteFrame->setFlippedX(true);
                case 13:
                    spriteFrame->setFlippedY(true);
                default:
                    break;
            }

			frame = 7;
			break;

		case 0:
		case 15:
			frame = 11;
			break;

		default:
			frame = -1;
	}

	return frame;
}
