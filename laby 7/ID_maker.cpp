#include <iostream>
#include "ID_maker.h"

int last_ID = 1;

int go_ID() {
    return last_ID++;
}