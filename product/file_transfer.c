#include "transfer.h"
  
static char* get_name() {
    return NULL;
}

static char* get_phone() {
    return NULL;
}

static char* get_address() {
    return NULL;
}

const static Transfer transfer = {
    .get_user_name = get_name,
    .get_user_phone = get_phone,
    .get_user_address = get_address
};

Transfer* get_file_transfer() {
    return &transfer;
}
