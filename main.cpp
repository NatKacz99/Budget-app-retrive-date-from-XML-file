#include <iostream>
#include "Markup.h"

using namespace std;

int main()
{
    CMarkup xml;

    bool fileExists = xml.Load( "exspenses.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    }
     if (xml.FindElem()) {
        xml.IntoElem();

        while (xml.FindElem()) {
            if (xml.GetTagName() == "date") {
                std::string date = xml.GetData();
                std::cout << "Date: " << date << std::endl;
            }
            xml.OutOfElem();
        }
    }
}

