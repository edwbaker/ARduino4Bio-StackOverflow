uint8_t * heapptr, * stackptr;

void setup() {
  Serial.begin(9600);
}

void loop() {
 increment(0); 
}

long increment(long i) {
  long stack;
  long heap;
  stack = (long)stackptr;
  heap  = (long)heapptr;
  check_mem();
  Serial.print(i);
  Serial.print(": Stack: ");
  Serial.print(stack);
  Serial.print(": Heap: ");
  Serial.println(heap);
  i++;
  int * array;
  if ( NULL == (array = (int *)malloc(10 * sizeof(i))) ) {
    Serial.println("malloc failed\n");
  }
  array[i-1] = 0;
  return increment(i);
}



void check_mem() {
  stackptr = (uint8_t *)malloc(4);          // use stackptr temporarily
  heapptr = stackptr;                     // save value of heap pointer
  free(stackptr);      // free up the memory again (sets stackptr to 0)
  stackptr =  (uint8_t *)(SP);           // save value of stack pointer
}
