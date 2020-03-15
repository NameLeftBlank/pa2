#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//Reads input from user (string) should be url
//parse URL to find protocol (http, https, ftp, ftps)
//domain must be (com, net, edu, biz, gov)
//port start with : (between 1 to 65535) *optional
//file path must start with '/' and end with '.html' or '.htm'
//parameter starts with '?' *optional
//if url is invalid must print "Invalid URL with following erroneous components:"
//Protocol: text is not valid protocol (http, https, ftp, ftps).
//Domain: text is invalid domain name.
//Port: port number must be between 1 and 65535
//File path: text is invalid file type
// sample URL: https://cs.utdallas.edu:80/directory/faculty/people.html?name=Robert
//random comment

using namespace std;

int main() {

string url;
string protocol;
string path;
string parameter;
string domain;
int pos = 0;
string port;
bool domainValid = true;
bool pathValid = true;
bool protocolValid = true;
bool portValid = true;
bool hasPort = false;
bool hasParameter = false;


cout << "Please enter a Url: ";
cin >> url;
protocol = url.substr(0,url.find(":", pos));
pos = url.find(":",url.find(":")+1);
if (protocol != "http" && protocol != "https" && protocol != "ftp" && protocol != "ftps") {
    protocolValid = false;
}
if(pos != -1)
{
    domain = url.substr(url.find(":")+3,(pos-(url.find(":")+3)));
    port = url.substr(pos+1,(url.find("/",pos)-(pos+1)));
    hasPort = true;
    int portNum = stoi(port);
    if(portNum < 1 || portNum > 65535) //|| port > "65535")
        {portValid = false;}
}
else
{
    domain =url.substr(url.find(":")+3, url.find("/",(url.find("/")+2))-(url.find(":")+3));
}
if(domain.find(".com") == -1 && domain.find(".net") == -1 && domain.find(".edu") == -1 && domain.find(".biz") == -1 && domain.find(".gov") == -1)
{
    domain = domain.substr(domain.find(".", domain.length()-4));
    domainValid = false;
}
pos=url.find("/",url.find(":")+3);
if(url.find("?") != -1)
{
    path = url.substr(pos, (url.find("?")-(pos)));
    parameter = url.substr(url.find("?")+1);
    hasParameter = true;
}
else
{
    path = url.substr(pos);
}
if(path.find("html") == -1 || path.find("htm") == -1)
{
    if(path.find(".") != -1)
    {
        path = path.substr(path.find("."));
    }
    pathValid = false;
}

if(pathValid != true || protocolValid !=  true || domainValid != true || portValid != true)
{
    if(pathValid != true)
    {
        cout << "File path: " + path + " is invalid file type.\n";
    }
    if(protocolValid != true)
    {
        cout << "Protocol: " + protocol + " is not a valid protocol.\n";
    }
    if(domainValid != true)
    {
        cout << "Domain: " + domain + " is an invalid domain name.\n";
    }
    if(portValid != true)
    {
        cout << "port: port number must be between 1 and 65535.\n";
    }
}
else
{
    cout << "Protocol: " << protocol;
    cout << "\nDomain: " << domain;
    if(hasPort == true)
        cout <<"\nPort: " << port;
    cout <<"\nFile path: " << path;
    if(hasParameter == true)
        cout <<"\nParameters: " << parameter;
}
return 0;


}
