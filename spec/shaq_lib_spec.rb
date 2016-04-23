require 'spec_helper'

describe ShaqLib do
  it 'has a version number' do
    expect(ShaqLib::VERSION).not_to be nil
  end

  describe "::kmers" do
    it "yields kmers" do
      str = "abcdef"
      ksize = 3
      expect { |b| ShaqLib.kmers(str, ksize, &b) }.
        to yield_successive_args("abc", "bcd", "cde", "def")
    end
  end
end
