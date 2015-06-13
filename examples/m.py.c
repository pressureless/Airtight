#include<stdlib.h>
#include<stdbool.h>
#include<stddef.h>
#include<string.h>
#include<stdarg.h>

typedef struct HString {
    char* chars;
    size_t length;
    size_t capacity;
} HString;

HString HStringFrom(char* s) {
    HString string;
    string.capacity = strlen(s) + 1;
    string.chars = (char*)malloc(sizeof(char) * string.capacity);
    string.length = string.capacity - 1;
    for(int j = 0;j < string.length;j ++) { string.chars[j] = s[j]; }
    string.chars[string.length] = '\0';
    return string;
}

HString h_add_HString_HString(HString z, HString a) {
    if (a.length + z.length + 1 >= z.capacity) {
        z.capacity *= 2;
        z.chars = (char*)(realloc(z.chars, sizeof(char) * z.capacity));
    }
    for(int j = 0;j < a.length;j ++) { z.chars[z.length + j] = a.chars[j]; }
    z.chars[z.length + a.length] = '\0';    
    z.length += a.length;

    return z;
}
int h_length_HString_int(HString string) {
    return string.length;
}

HString h_print_HString_HString(HString string) {
    printf("%s\n", string.chars);
    return string;
}

HString h_str_int_HString(int value) {
    char buffer[22];
    snprintf(buffer, 22, "%d", value);
    HString z = HStringFrom(buffer);
    return z;
}

HString h_str_HString_HString(HString string) {
    return string;
}


typedef struct HList_int {
	int* values;
	size_t length;
	size_t capacity;
} HList_int;

HList_int h_append_HList_int_int_HList_int(HList_int list, int elem) {
	if(list.length + 1 > list.capacity) {
		list.capacity *= 2;
		list.values = (int*)realloc(list.values, sizeof(int) * list.capacity);
	}
	list.values[list.length] = elem;
	list.length++;
	return list;
}

HList_int h_pop_HList_int_int_HList_int(HList_int list, int elem) {
	list.length--;
	return list;
}

int h_length_HList_int_int(HList_int list) {
	return list.length;
}

int h_index_HList_int_int_int(HList_int list, int index) {
	return list.values[index];
}

HList_int h_slice_HList_int_int_int_HList_int(HList_int z, int from, int to) {
	HList_int list;
	list.values = (int*)malloc(sizeof(int) * (to - from));
	list.length = to - from;
	list.capacity = to - from;
	for(int j = from;j < to;j ++) {
		list.values[j - from] = z.values[j];
	}
	return list;
}

HList_int HList_intOf(size_t count, ...) {
	va_list ap;
	HList_int list;
	list.values = (int*)(malloc(sizeof(int) * (count + 1)));
	list.length = count;
	list.capacity = count + 1;
	va_start(ap, count);
	for(int j = 0;j < count;j ++) { list.values[j] = va_arg(ap, int); }
	return list;
}

HString h_str_HList_int_HString(HList_int list) {
	HString z = HStringFrom("[");

	for(int j = 0;j < list.length - 1;j ++) {
		z = h_add_HString_HString(z, h_str_int_HString(list.values[j]));
		z = h_add_HString_HString(z, HStringFrom(" "));
	}
	z = h_add_HString_HString(z, h_str_int_HString(list.values[list.length - 1]));
	z = h_add_HString_HString(z, HStringFrom("]"));
	return z;
}



	
typedef struct HList_HString {
	HString* values;
	size_t length;
	size_t capacity;
} HList_HString;

HList_HString h_append_HList_HString_HString_HList_HString(HList_HString list, HString elem) {
	if(list.length + 1 > list.capacity) {
		list.capacity *= 2;
		list.values = (HString*)realloc(list.values, sizeof(HString) * list.capacity);
	}
	list.values[list.length] = elem;
	list.length++;
	return list;
}

HList_HString h_pop_HList_HString_HString_HList_HString(HList_HString list, HString elem) {
	list.length--;
	return list;
}

int h_length_HList_HString_int(HList_HString list) {
	return list.length;
}

HString h_index_HList_HString_int_HString(HList_HString list, int index) {
	return list.values[index];
}

HList_HString h_slice_HList_HString_int_int_HList_HString(HList_HString z, int from, int to) {
	HList_HString list;
	list.values = (HString*)malloc(sizeof(HString) * (to - from));
	list.length = to - from;
	list.capacity = to - from;
	for(int j = from;j < to;j ++) {
		list.values[j - from] = z.values[j];
	}
	return list;
}

HList_HString HList_HStringOf(size_t count, ...) {
	va_list ap;
	HList_HString list;
	list.values = (HString*)(malloc(sizeof(HString) * (count + 1)));
	list.length = count;
	list.capacity = count + 1;
	va_start(ap, count);
	for(int j = 0;j < count;j ++) { list.values[j] = va_arg(ap, HString); }
	return list;
}

HString h_str_HList_HString_HString(HList_HString list) {
	HString z = HStringFrom("[");

	for(int j = 0;j < list.length - 1;j ++) {
		z = h_add_HString_HString(z, h_str_HString_HString(list.values[j]));
		z = h_add_HString_HString(z, HStringFrom(" "));
	}
	z = h_add_HString_HString(z, h_str_HString_HString(list.values[list.length - 1]));
	z = h_add_HString_HString(z, HStringFrom("]"));
	return z;
}



	
HList_HString h_f0_intREFHString_HList_int_HList_HString(HString (*h_f)(int), HList_int h_s){
    HList_HString h_out = HList_HStringOf(0);
    for(int i=0;i<h_length_HList_int_int(h_s);i++){
        int h_i = h_index_HList_int_int_int(h_s, i);
        h_out = h_append_HList_HString_HString_HList_HString(h_out, (*h_f)(h_i));
        2;
        h_out;
    }
;
    return h_out;
}

HString h_even_int_HString(int h_a){
    return HStringFrom("'wtf'");
}

int main(){
    h_print_HString_HString(h_str_HList_HString_HString(h_f0_intREFHString_HList_int_HList_HString(&h_even_int_HString, HList_intOf(1, 2))));
    return 0;
}
