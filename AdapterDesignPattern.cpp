#include<bits/stdc++.h>
using namespace std;

// Adapter Design Pattern: Converting incompatible data (XML to JSON)

class XMLData {
private:
    string xmlData;

public:
    XMLData(string pxmlData) {
        xmlData = pxmlData;
    }

    string getXMLData() {
        return xmlData;
    }
};

class DataAnalyticsTool {
private:
    string jsonData;

public:
    DataAnalyticsTool() {}
    DataAnalyticsTool(string pjsonData) {
        jsonData = pjsonData;
    }

    virtual void analyseData() {
        cout << "Analysing Data " << jsonData << "\n";
    }
};

// a child class and a parent class can have different constructor 

// but for that we should add the default constructor in the parent class 

class Adapter : public DataAnalyticsTool {
private:
    XMLData* xmlData;

public:
    Adapter(XMLData* pxmlData) : DataAnalyticsTool("") {  // Passing empty JSON to base class
        xmlData = pxmlData;
    }

    void analyseData() override {
        // Simulate XML to JSON conversion (just a message for now)
        cout << "Converting the XML data: '" << xmlData->getXMLData() << "' to JSON data...\n";
        cout << "Analyzing the converted JSON data.\n";
    }
};

class Client {
public:
    void processData(DataAnalyticsTool* tool) {
        tool->analyseData();
    }
};

int main() {
    XMLData* xmlData = new XMLData("sample xml data");

    // Client uses the Adapter to handle XML -> JSON conversion without modification
    DataAnalyticsTool* tool = new Adapter(xmlData);
    
    // Client uses the tool without worrying about XML or JSON
    Client* c = new Client();
    c->processData(tool);

    // Clean up dynamically allocated memory
    delete xmlData;
    delete tool;
    delete c;

    return 0;
}
