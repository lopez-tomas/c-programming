#include <stdio.h>

#include "../binaryArchives/binaryFiles.h"
#include "dynamic/Queue.h"
#include "exercises.h"

int obtainingMovementsFiles(const char* movements_all__filename, const char* movements_greater__filename, const char* movements_minor__filename) {
    FILE* p__mov_all;
    FILE* p__mov_greater;
    FILE* p__mov_minor;

    t_Queue queue;
    t_Movements mov;

    unsigned acc_num;
    float acum;

    createQueue(&queue);

    p__mov_all = fopen(movements_all__filename, "rb");
    if( !p__mov_all ) {
        return MOV_ALL__ERR;
    }

    p__mov_greater = fopen(movements_greater__filename, "wb");
    if( !p__mov_greater ) {
        fclose(p__mov_all);
        return MOV_GREATER__ERR;
    }

    p__mov_minor = fopen(movements_minor__filename, "wb");
    if( !p__mov_minor ) {
        fclose(p__mov_all);
        fclose(p__mov_greater);
        return MOV_MINOR__ERR;
    }

    fread(&mov, sizeof(t_Movements), 1, p__mov_all);

    while( !feof(p__mov_all) ) {
        acc_num = mov.account_number;
        acum = 0;

        while( mov.account_number == acc_num ) {
            acum += mov.value;

            if( !push(&queue, &mov, sizeof(t_Movements)) ) {
                if( !isEmpty(&queue) ) {
                    emptyQueue(&queue);

                    fclose(p__mov_all);
                    fclose(p__mov_greater);
                    fclose(p__mov_minor);

                    return PUSH_QUEUE__ERR;
                }
            }

            fread(&mov, sizeof(t_Movements), 1, p__mov_all);
        }

        while( !isEmpty(&queue) ) {
            pop(&queue, &mov, sizeof(t_Movements));

            if( acum >= MAX_VALUE ) {
                fwrite(&mov, sizeof(t_Movements), 1, p__mov_greater);
            } else {
                fwrite(&mov, sizeof(t_Movements), 1, p__mov_minor);
            }
        }

        fread(&mov, sizeof(t_Movements), 1, p__mov_all);
    }

    fclose(p__mov_all);
    fclose(p__mov_greater);
    fclose(p__mov_minor);

    return SUCCESS;
}
