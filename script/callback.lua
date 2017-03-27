io.write("Calling callback() ...\n")
local value = callback("First", "Second", 3)
io.write(string.format("callback() returned: %s \n", tostring(value)))
