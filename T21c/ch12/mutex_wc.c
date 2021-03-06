#include "string_utilities.h"
#include <pthread.h>
#include <glib.h> //mutexes

long int global_wc;

typedef struct{
    int wc;
    char *docname;
} wc_struct;

void *wc(void *voidin){
    wc_struct *in = voidin;
    char *doc = string_from_file(in->docname);
    if (!doc) return NULL;
    static GMutex count_lock;
    
    char *delimiters = " `~!@#$%^&*()_-+={[]}|\\;:\",<>./?\n\t";
    ok_array *words = ok_array_new(doc, delimiters);
    if (!words) return NULL;
    in->wc = words->length;
    ok_array_free(words);
    g_mutex_lock(&count_lock);
    for (int i=0; i< in->wc; i++)
        global_wc++; //a slow global_wc += in->wc;
    g_mutex_unlock(&count_lock);
    return NULL;
}

int main(int argc, char **argv){
    argc--;
    argv++; //step past the name of the program.

    pthread_t threads[argc];
    wc_struct s[argc];
    for (int i=0; i< argc; i++){
        s[i] = (wc_struct){.docname=argv[i]};
        pthread_create(&threads[i], NULL, wc, &s[i]);
    }
    
    for (int i=0; i< argc; i++) pthread_join(threads[i], NULL);
    
    for (int i=0; i< argc; i++) printf("%s:\t%i\n",argv[i], s[i].wc);
    printf("The total: %li\n", global_wc);
}