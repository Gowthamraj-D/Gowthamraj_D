

typedef struct {
    int buf[256];
    int input_pos;  // Индекс для добавления элементов (push)
    int output_pos; // Индекс для удаления элементов (pop)
} MyQueue;

// Создание очереди
MyQueue* myQueueCreate() {
    MyQueue *Queue = malloc(sizeof(MyQueue));
    Queue->input_pos = 0;
    Queue->output_pos = 0;
    return Queue;
}

// Добавление элемента в очередь
void myQueuePush(MyQueue* obj, int x) {
    obj->buf[obj->input_pos] = x;
    obj->input_pos++;
}

// Удаление и возвращение элемента из очереди
int myQueuePop(MyQueue* obj) {
    if (obj->output_pos == obj->input_pos) {
        return -1; // Очередь пуста, возвращаем ошибку
    }
    int res = obj->buf[obj->output_pos];
    obj->output_pos++;
    return res;
}

// Получение элемента на передней позиции очереди без его удаления
int myQueuePeek(MyQueue* obj) {
    if (obj->output_pos == obj->input_pos) {
        return -1; // Очередь пуста, возвращаем ошибку
    }
    return obj->buf[obj->output_pos];
}

// Проверка на пустоту очереди
bool myQueueEmpty(MyQueue* obj) {
    return obj->output_pos == obj->input_pos;
}

// Освобождение памяти
void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
