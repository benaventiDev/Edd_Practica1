#include "Buffer.h"

Buffer::Buffer() {}

string Buffer::remTabs(string line)
{
    int tab = line.find("\t");
    if(tab == line.npos) // This is in case there is no tab in the string line
        return line;
    else
        return remTabs(line.replace(tab, 1, "    ")); // calls recursively itself until replaces all tabs with spaces
}

void Buffer::insertLine(string line, int n)
{
    line = remTabs(line);                   // Conversion (happens every time) removes tabs in the string
    lines.insert(lines.begin()+n, line); // inserts line within the vector at the n position.
}

void Buffer::appendLine(string line)
{
    line = remTabs(line);
    lines.push_back(line); // just adds the element at the end
}

void Buffer::removeLine(int n)
{
    lines.erase(lines.begin()+n); // remove line at certain position
}

