# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'shaq_lib/version'

Gem::Specification.new do |spec|
  spec.name          = "shaq_lib"
  spec.version       = ShaqLib::VERSION
  spec.authors       = ["Ryan Moore"]
  spec.email         = ["moorer@udel.edu"]
  spec.license       = "GPLv3"

  spec.summary       = %q{Library code for Shaq assembler}
  spec.description   = %q{Library code for Shaq assembler}
  spec.homepage      = "https://github.com/mooreryan/shaq_lib"

  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib", "ext"]

  spec.platform      = Gem::Platform::RUBY
  spec.extensions    = ["ext/shaq_lib/extconf.rb"]

  spec.add_development_dependency "bundler", "~> 1.11"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec", "~> 3.0"
  spec.add_development_dependency "rake-compiler", "~> 0.9.7"
end
