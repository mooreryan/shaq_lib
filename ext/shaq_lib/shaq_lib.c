#include <ruby.h>

static VALUE kmers(VALUE klass, VALUE str, VALUE ksize)
{
  long i = 0;
  long j = 0;
  long k = NUM2LONG(ksize);
  long num_kmers = RSTRING_LEN(str) - k + 1;

  char *c_str = RSTRING_PTR(str);

  for (i = 0; i < num_kmers; ++i) {
    char substr[k+1];

    for (j = 0; j < k; ++j) {
      substr[j] = c_str[i+j];
    }
    substr[j] = '\0';

    /* for this, put the length without the null char */
    rb_yield(rb_str_new(substr, k));
  }

  return str;
}

void Init_shaq_lib(void)
{
  VALUE ModuleShaqLib = rb_define_module("ShaqLib");
  rb_define_singleton_method(ModuleShaqLib, "kmers", kmers, 2);
}
