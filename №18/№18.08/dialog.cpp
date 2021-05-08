#pragma once
#include "dialog.h"
#include <iostream>

Dialog::Dialog()
{
    endState = 0;
}

Dialog::~Dialog(){}

void Dialog::getEvent(TEvent &event)
{
    std::string opInt = "+-?/qam";
    std::string s, param;
    
    char code;
    std::cout << ">";
    std::cin >> s;
    code = s[0];
    if(opInt.find(code)>=0)
    {
        event.what = evMessage;
        switch (code)
        {
        case 'm': event.command = cmMake; break;
        case '+': event.command = cmAdd; break;
        case '-': event.command = cmDel; break;
        case 's': event.command = cmShow; break;
        case '?': event.command = cmGet; break; 
        case 'q': event.command = cmQuit; break;        
        }
        if(s.length()>1)
        {
            param = s.substr(1,s.length()-1);
            int A = atoi(param.c_str());
            event.a = A;
        }
    }
    else
    {
        event.what = evNothing;
    }
}

int Dialog::execute()
{
    TEvent event;
    do
    {
        endState = 0;
        getEvent(event);
        handleEvent(event);
    } while (!valid());
    return endState;
}

int Dialog::valid()
{
    if(endState == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void Dialog::clearEvent(TEvent &event)
{
    event.what = evNothing;
}

void Dialog::endExec()
{
    endState = 1;
}

void Dialog::handleEvent(TEvent &event)
{
    if(event.what == evMessage)
    {
        switch (event.command)
        {
        case cmMake:
            start = new Node;  
            currentPosition = start;
            size = 0;
            start->data = nullptr;
            start->next = nullptr;
            clearEvent(event);
            break;
        case cmAdd: add(); clearEvent(event); break;
        case cmDel: del(); clearEvent(event); break;
        case cmShow: show(); clearEvent(event); break;
        case cmGet: getInfo(event.a); break;
        case cmQuit: endExec(); clearEvent(event); break;
        }
    }
}