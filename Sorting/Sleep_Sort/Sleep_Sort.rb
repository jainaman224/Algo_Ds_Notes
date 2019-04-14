#!/usr/bin/env ruby

def sleep_sort(args)
  threads = []
  mutex = Mutex.new

  args.each do |value|
    threads << Thread.new do
      sleep value.to_f / 1000
      mutex.synchronize do
        print value.to_s + " "
      end
    end
  end

  threads.each do |thread|
    thread.join
  end
end

x = [2, 4, 3, 1, 6, 8, 4]
sleep_sort(x)


# Output
# 1 2 3 4 4 6 8
