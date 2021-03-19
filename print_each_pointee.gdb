define print_each_pointee
  if $argc == 0
    help print_each_pointee
  else
    set $size = $arg0.size()
    set $i = 0
    while $i < $size
      printf "$arg0[%u]: ", $i
      p *$arg0[$i]
      set $i++
    end
  end
end

document print_each_pointee
  Prints each pointee of STL container member
  Syntax: print_each_pointee <container>
end

set print pretty on
set print object on
