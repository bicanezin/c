typedef struct point{
    float x;
    float y;
} Point;

// Prot�tipos

Point * point_create(float x, float y);

void point_fre(Point * p);

void point_print(Point * p);

float point_distance(Point * a, Point *b);

// Implementa��o

Point * point_create(float x, float y){
    Point * p = (Point*) malloc(sizeof(Point));
    
    if(p == NULL){
        printf("Houve um erro na cria��o do ponto.\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}

void point_free(Point * p){
    free(p);
    
    printf("Ponto, removido com sucesso.\n");
}

void point_print(Point * p){
    printf("X: %0.2f, Y: %0.2f\n", p->x, p->y);
}

float point_distance(Point *a, Point *b){
    float dist;
    
	dist = sqrt( pow (a->x - b->x, 2) + pow (a->y - b->y, 2));
	
    printf("A dist�ncia entre os pontos �: %0.2f\n", dist);
}
