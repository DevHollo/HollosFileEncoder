char_list = {
  "a": "9a&", "b": "e*;", "c": "{~>", "d": ";iv", "e": "ps&", "f": "ps5", "g": "xn^", "h": "8f}", "i": "$2*",
  "j": ":x$", "k": "^rv", "l": "#c~", "m": "*v$", "n": "}l@", "o": "o%;", "p": "fzb", "q": "c=3", "r": ";#y",
  "s": "%*z", "t": "_u>", "u": "(3!", "v": "k+s", "w": "yn_", "x": "{t.", "y": "<<m", "z": "=j>", "A": "p!s",
  "B": "-^r", "C": "..+", "D": "0?8", "E": "+7h", "F": "q2^", "G": "h2;", "H": "1jc", "I": "xx%", "J": "ioq",
  "K": "!n$", "L": "}$5", "M": "7$$", "N": "5<#", "O": "n:g", "P": "zar", "Q": "lo(", "R": "xs!", "S": "j%>",
  "T": "lh~", "U": "r)v", "V": "/-b", "W": "0*#", "X": "l2>", "Y": "t6;", "Z": "4l!", "`": "1;c", "~": "ex*",
  "!": "d(2", "@": "/s%", "#": "01=", "$": "/&b", "%": "$=k", "^": ":<n", "&": "2#g", "*": "li=", "(": "#h5",
  ")": "z`(", "_": "2cw", "+": "_<;", "-": "0?_", "=": "c+u", "[": "y?#", "]": "r6o", "{": "vra", "}": "/$#",
  "|": "d9<", "\\": "tri", ";": "7o&", "'": "@22", "\"": "hx`", ":": "{_y", "<": "`/k", ">": ")3s", "?": "bk!",
  "/": "dgr", ".": ";{l", ",": "*q;", "1": "_-t", "2": "tqn", "3": "7g1", "4": "$z+", "5": "*:f", "6": "db5",
  "7": "/_?", "8": "g49", "9": "xg)", "0": "+o}"
}

def encode(data: str) -> str:
  encoded_data = ""
  for char in data:
      if char in char_list:
          encoded_data += str(char_list[char])
      else:
          # Keep non-mapped characters as they are
          encoded_data += char
  return encoded_data

def decode(data: str) -> str:
  decoded_data = ""
  reverse_char_list = {v: k for k, v in char_list.items()}
  i = 0
  while i < len(data):
      found = False
      for length in range(3, 0, -1):
          current_slice = data[i:i+length]
          if current_slice in reverse_char_list:
              decoded_data += reverse_char_list[current_slice]
              i += length
              found = True
              break
      if not found:
          # Keep non-mapped characters as they are
          decoded_data += data[i]
          i += 1
  return decoded_data