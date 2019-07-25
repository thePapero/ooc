/**
 * Singleton class
 */

typedef struct Singleton Singleton;

struct Singleton {
    int data0;
};

Singleton* Singleton_create();
void Singleton_destroy(Singleton* me);

void Singleton_init(Singleton* me);
void Singleton_cleanup(Singleton* me);