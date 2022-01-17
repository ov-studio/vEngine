---
description: Retrieves vector's w coord.
---

# getW

### ━ Syntax

<mark style="color:red;">**`[float w] vector:getW()`**</mark>

### ━ Usage

```lua
local cVector = vEngine.math.vector(10, 20, 30, 40) --Creates a new vector
local vectorCoordW = cVector:getW() --Retrieves vector's w coord
print(vectorCoordW) --Prints w coord of our vector
```