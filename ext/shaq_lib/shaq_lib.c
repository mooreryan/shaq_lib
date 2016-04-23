#include <ruby.h>

static VALUE kmers(VALUE klass, VALUE str, VALUE ksize)
{
  long i = 0;
  long k = NUM2LONG(ksize);
  long num_kmers = RSTRING_LEN(str) - k + 1;

  for (i = 0; i < num_kmers; ++i) {
    rb_yield(rb_str_substr(str, i, k));
  }

  return str;
}

static VALUE submers(VALUE klass, VALUE str)
{
  long strlen = RSTRING_LEN(str);
  VALUE s1, s2;

  s1 = rb_str_substr(str, 0, strlen-1);
  s2 = rb_str_substr(str, 1, strlen-1);

  VALUE ary = rb_ary_new2(2);

  rb_ary_push(ary, s1);
  rb_ary_push(ary, s2);

  return ary;
}

/* static VALUE count(VALUE klass, VALUE ary) */
/* { */
/*   long len = RARRAY_LEN(ary); */

/*   VALUE hash = rb_hash_new(); */

/*   rb_hash_aset(hash, rb_str_new2("mykey"), rb_str_new2("myvalue")); */

/*   return len; */
/* } */

void Init_shaq_lib(void)
{
  VALUE ModuleShaqLib = rb_define_module("ShaqLib");
  rb_define_singleton_method(ModuleShaqLib, "kmers", kmers, 2);
  rb_define_singleton_method(ModuleShaqLib, "submers", submers, 1);
  /* rb_define_singleton_method(ModuleShaqLib, "count", count, 1); */
}
