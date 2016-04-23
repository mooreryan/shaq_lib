require "bundler/gem_tasks"
require "rspec/core/rake_task"
require "rake/extensiontask"

RSpec::Core::RakeTask.new(:spec)

task :default => :spec

Rake::ExtensionTask.new do |ext|
  ext.name    = "shaq_lib"
  ext.ext_dir = "ext/shaq_lib"
  ext.lib_dir = "lib/shaq_lib"
end

Rake::Task[:spec].prerequisites << :compile
