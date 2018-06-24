#include "LoaderCompany.h"
#include "cocos2d.h"

using namespace cocos2d;
using namespace tinyxml2;

LoaderCompany::LoaderCompany(CompaniesManager* companiesManager):
		companiesManager(companiesManager)
{
}

LoaderCompany::~LoaderCompany()
{
}

bool LoaderCompany::load(const std::string &path)
{
	XMLDocument doc;
	doc.LoadFile(FileUtils::getInstance()->fullPathForFilename(path).c_str());
	
	XMLNode* root = doc.FirstChildElement("area")->FirstChildElement("companies");
	
	for( XMLElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if( strcmp(e->Value(), "company") == 0 )
		{
			companiesManager->addNew(createCompanyOfXML(e));
		}
	}
	
	return Loader::load(path);
}

Company* LoaderCompany::createCompanyOfXML(tinyxml2::XMLElement* object)
{
	Company* ret = new Company;
	ret->setId(atoi(object->Attribute("id")));
	ret->setMoney(atoi(object->Attribute("money")));
	
	const char* typeOwner = object->Attribute("typeOwner", nullptr);
	if( typeOwner )
	{
		ret->setTypeOwner(typeOwner);
	}
	
	const char* owner = object->Attribute("owner", nullptr);
	if( owner )
	{
		ret->setOwner(atoi(owner));
	}
	
	
	return ret;
}
