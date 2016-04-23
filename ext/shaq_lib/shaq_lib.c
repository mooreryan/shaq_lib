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

static VALUE submers(VALUE klass, VALUE str)
{
  long ksize = RSTRING_LEN(str) - 1;
  long i = 0;

  char k1[ksize+1];
  char k2[ksize+1];

  char *c_str = RSTRING_PTR(str);

  for (i = 0; i < ksize; ++i) {
    k1[i] = c_str[i];
    k2[i] = c_str[i+1];
  }
  k1[i] = '\0';
  k2[i] = '\0';

  VALUE k1_r = rb_str_new(k1, ksize);
  VALUE k2_r = rb_str_new(k2, ksize);

  VALUE ary = rb_ary_new2(2);
  rb_ary_push(ary, k1_r);
  rb_ary_push(ary, k2_r);

  return ary;
}

void Init_shaq_lib(void)
{
  VALUE ModuleShaqLib = rb_define_module("ShaqLib");
  rb_define_singleton_method(ModuleShaqLib, "kmers", kmers, 2);
  rb_define_singleton_method(ModuleShaqLib, "submers", submers, 1);
}
