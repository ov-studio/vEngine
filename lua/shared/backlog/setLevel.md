---
description: Sets backlog level.
---

# setLevel

{% hint style="danger" %}
**API available only on Client Side.**
{% endhint %}

### ━ Syntax

<mark style="color:red;">**`[bool status] setLevel(int level)`**</mark>

### ━ Levels

* **1 - None**
* **2 - Default**
* **3 - Warning**
* **4 - Error**

### ━ Usage

```lua
local result = vEngine.backlog.setLevel(2) --Set our backlog level to default mode
print(result) --Prints result
```