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

  describe "::submers" do
    it "returns first and last k-1mer of the kmer" do
      str = "abcd"
      expect(ShaqLib.submers str).to eq %w[abc bcd]
    end
  end

  # describe "::count" do
  #   it "counts unique args" do
  #     hash = { "1" => 2, "2" => 1 }
  #     expect(ShaqLib.count ["1", "1", "2"]).to eq hash
  #   end
  # end
end
