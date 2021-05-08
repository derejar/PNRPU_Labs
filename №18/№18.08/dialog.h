#pragma once
#include "event.h"
#include "list.h"

class Dialog : public List
{
    protected:
        int endState;
    public:
        Dialog();
        virtual ~Dialog();
        virtual void getEvent(TEvent &event);
        virtual int execute();
        virtual void handleEvent(TEvent &event);
        virtual void clearEvent(TEvent &event);
        int valid();
        void endExec();
};
#include "dialog.cpp"