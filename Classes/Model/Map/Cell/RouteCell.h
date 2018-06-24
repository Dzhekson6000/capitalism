#ifndef CAPITALISM_ROUTECELL_H
#define CAPITALISM_ROUTECELL_H

#include "Cell.h"

class RouteCell: public Cell
{
protected:
	int getFrame() override;
};


#endif //CAPITALISM_ROUTECELL_H
