#include <stdio.h>
#include <stdlib.h>
#include "Methods.h"

int end_insert_input() {
    if (local_text == NULL) {

        local_text = calloc(local_text_rows, sizeof(char*));
        local_text[0] = calloc(local_text_chars, sizeof(char));

        if (local_text_chars < user_input_len) {
            local_text_chars = user_input_len;
            local_text[0] = realloc(local_text[0], local_text_chars);
        } 
        strcat(local_text[0], user_input);
    }

    // ------ will be implemented later
    /*else 
    {
        for (int i = 0; i < local_text_rows; i++)
        {
            if (local_text[i + 1] == '\0') {
                local_text[i] = calloc(local_text_chars, sizeof(char));

                if (local_text_chars < user_input_len) {
                    local_text_chars = user_input_len;
                    local_text[i] = realloc(local_text[i], local_text_chars);
                }
                strcat(local_text[i], user_input);
                break;
            }
        }
    }*/
    // ---------------------------

    strcat(local_text[0], user_input);
    free(user_input);
    return 0;
}
