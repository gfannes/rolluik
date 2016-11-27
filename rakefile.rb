require(File.join(ENV['gubg'], 'shared'))
require('gubg/build/Executable')
include GUBG

def each_submod(&block)
    submods = %w[build arduino].map{|n|"gubg.#{n}"}
    GUBG::each_submod(submods, &block)
end

task :clean do
    rm_rf '.cache'
end

task :declare do
    each_submod{sh 'rake declare'}
end
task :define => :declare do
    each_submod{sh 'rake define'}
end

task :run => :define do
    sh "sudo chmod 777 /dev/ttyACM0"
    arch = :uno
    rolluik = Build::Executable.new('rolluik', arch: arch)
    rolluik.add_sources('src/main.cpp')
    rolluik.add_library_path(shared_dir("lib/#{arch}"))
    # rolluik.add_library('arduino-core')
    rolluik.build
end
