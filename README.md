# 3D_Maze_Game

---
created: 2024-02-22T00:20:19 (UTC +01:00)
tags: []
source: https://intranet.alxswe.com/concepts/133
author: 
---

# Concept: Maze project | Lagos Intranet

> ## Excerpt
> The goal of this project is to create a game in 3D using raycasting !

---
[

](https://intranet.alxswe.com/)

-   [
    
    My Planning
    
    ](https://intranet.alxswe.com/planning/me)
-   [
    
    Projects
    
    ](https://intranet.alxswe.com/projects/current)
-   [
    
    QA Reviews I can make
    
    ](https://intranet.alxswe.com/corrections/to_review)
-   [
    
    Evaluation quizzes
    
    ](https://intranet.alxswe.com/dashboards/my_current_evaluation_quizzes)

___

-   [
    
    Curriculums
    
    ](https://intranet.alxswe.com/dashboards/my_curriculums)
-   [
    
    Concepts
    
    ](https://intranet.alxswe.com/concepts)
-   [
    
    Conference rooms
    
    ](https://intranet.alxswe.com/dashboards/video_rooms)
-   [
    
    Servers
    
    ](https://intranet.alxswe.com/servers)
-   [
    
    Sandboxes
    
    ](https://intranet.alxswe.com/user_containers/current)
-   [
    
    Tools
    
    ](https://intranet.alxswe.com/dashboards/my_tools)
-   [
    
    Video on demand
    
    ](https://intranet.alxswe.com/dashboards/videos)

___

-   [
    
    Peers
    
    ](https://intranet.alxswe.com/users/peers)
-   [
    
    Captain's Logs
    
    ](https://intranet.alxswe.com/dashboards/my_captain_log)

___

-   [
    
    Discord
    
    ](https://discord.com/app)
    
    [
    
    My Profile
    
    ](https://intranet.alxswe.com/users/my_profile)
    

Curriculum

SE Foundations Average: 94.98%

-   [
    
    SE Foundations Average: 94.98%
    
    
    
    ](https://intranet.alxswe.com/curriculums/1/observe)

# Maze project

## Background Context

The goal of this project is to create a game in 3D using raycasting !

You don’t have to do the tasks in order, except for the first one (obviously), or if a task depends on a previous one

You have a link to a very good and very long tutorial about raycasting in the `Tips and links` section below, so read it very carefully, and practice !

Please have a lot of fun doing this project !

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/8970c3ee63d8149b93e30229276c3f7580ac9447.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=c2a1e1c51ad80ecc91c513b3520e45b3ec3debadb8711211dad34ad0818e387a)

## Requirements

### General

-   All your files will be compiled on Ubuntu 14.04 LTS, using gcc (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4
-   We will use the **gcc flags** `-Wall` `-Werror` `-Wextra` and `-pedantic`
-   All your functions must be commented
-   Your functions should be **maximum 40 lines** long (one statement per line)
-   Your functions should be **maximum 80 columns** long
-   No more than **5 functions** per file

### Betty

-   Your entire repository will be checked using [Betty](https://intranet.alxswe.com/rltoken/f6sw5PyQ4Mj4FUVBRdAfXg "Betty")
-   Don’t push any object files `.o` or temporary files `*~`, or any unused source file if you don’t want to lose points !
-   It is advised to always keep a clear organisation in your repository. For example, store all your sources in a `src` directory, and all your headers in a `inc`, `headers` or `dependencies` folder

## More Info

### Tips and links

-   [SDL2 - Get started.pdf](https://intranet.alxswe.com/rltoken/pMnvq93vpbAh9q6inKQMuQ "SDL2 - Get started.pdf")
-   [SDL2 tutorials](https://intranet.alxswe.com/rltoken/oona0Kd1yVyjHQGoJaV_aw "SDL2 tutorials")
-   Be careful with tutorials/help online: We are using `SDL2`, and not `SDL-1.2` !
-   [RAYCASTING !!!](https://intranet.alxswe.com/rltoken/vRw7CP21mUmKFDdrQjQ2GA "RAYCASTING !!!")
-   [Alternative Raycasting Tutorial](https://intranet.alxswe.com/rltoken/dnQwzgrDUEhFXIF8sNivkg "Alternative Raycasting Tutorial")

### Important

-   Don’t forget to **install SDL2** [SDL2 tutorials](https://intranet.alxswe.com/rltoken/oona0Kd1yVyjHQGoJaV_aw "SDL2 tutorials")
-   There are no forbidden functions for this project. You are allowed to use any system call and/or standard library function.
-   You are allowed to use [all the functions provided by SDL2](https://intranet.alxswe.com/rltoken/bmGynXNHzUObCE08XuoCQg "all the functions provided by SDL2")

## Tasks

### 0\. Walls !

In this first part, you’ll have to:

-   Create a window with SDL2
-   Use [raycasting](https://intranet.alxswe.com/rltoken/vRw7CP21mUmKFDdrQjQ2GA "raycasting") to draw walls on your window !
-   You don’t need to be able to rotate the camera during the execution in this part, but you must provide a way to change the angle of the camera in your code to see if it works after recompiling it
-   The color of the walls must be different from the color of the ground/ceil
-   The map doesn’t need to be parsed from a file, but you must provide a way to modify it in your code to see if it works after recompiling it. (e.g. using an array of arrays of integers or characters).

Example:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/7e897a79ffe0d990856e021f4e1e6cdbb0ff5395.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=0053fedc22fbf67ef8abe2fffa8645c54ab0c3bc3a8f1053edafca626108823e)

In the following image, the camera is the red square, and the visible area is painted in green:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/f280499b4f118ae102c62251b87dfd6aff737795.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=5ca67ba5323fba773e170d06bb743e5b6c7e78922a25e2930a550c18cb57c013)

### 1\. Orientation

In this part, you must draw a different color depending on the orientation of the walls.

-   You must at least draw walls facing `NORTH and SOUTH` in a different color from walls facing `EAST and WEST`.

Example:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/bc20224777aa01d6b9b6f6944421beb1850fecb6.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=5c3cbd0cc7b2198e9242280567f7630d84d88863084000f83731cc61df96af1c)

### 2\. Rotation

You must provide a way to rotate the camera during the execution.

-   For example, you can rotate the camera when the `left,right` arrows are pressed on the keyboard.
-   Or you can rotate the camera when the mouse moves, just like a FPS game !

Example:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/7e322c5b857225f95fcf63795f5d68f954ab4474.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d0ca6d597806a0cf23d0d9bd21b97e28427f3a5952609cd7da69d954672405ab)

### 3\. Move

You must provide a way to move the camera during the execution.

-   For example, you can move the camera when the `w,a,s,d` keys are pressed on the keyboard.

Example:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/410f88f83b1de01b8fc2349d6c89a2743ba933a6.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=10f15e7829bbcf5b73c430f614869390fb683300b02fa23774dcb437df2d4d9e)

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/491510b693b38cf88f0d6e8917f6dc467e507635.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=0028552b62eb00f2b7c0adebce3dda0c317dd5cc11fc2ea5916b08ec2716f653)

### 4\. Ouch !

In this part, you must handle the collisions of the player (yes, let’s call the camera `player` now, it’s getting serious) with the walls.

-   The player must not be able to enter walls
-   You can make the player slide on the walls instead of just stop it.

### 5\. Parser

In this part you must implement a parser to get the map from a file.

-   You are free to define the standards of your map (The character for a wall, the character for nothing, the extension of the file if you want, …)
-   Your program will need a parameter to run which will be the path to the map file

### 6\. Draw the map

In this part, you must draw the map on the window.

-   You’re free to draw the map where you want, with the color you want, …
-   You must provide a way to enable/disable it during the execution
-   Include the player’s line of sight in the map

### 7\. Coding style + Documentation

-   Check if you code fits the [Holberton School coding style](https://intranet.alxswe.com/rltoken/R15Tf-sVTHL3SWCnEQ7bog "Holberton School coding style").
-   Check if your code is well documented and respect the [Holberton School documentation format](https://github.com/alx-tools/Betty/blob/master/kernel-doc.pl "Holberton School documentation format")

You can check all of this by yourself, just follow the instructions on [this repository](https://intranet.alxswe.com/rltoken/f6sw5PyQ4Mj4FUVBRdAfXg "this repository")

**Be careful**

The check will be done on each file present on your turn in repository. Even the files that was not required. So don’t forget to always keep your turn in directory clean.

### 8\. Textures

In this part you have to add textures on your walls !

Example

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/c6106183de275a10df8994437f710118ee59d654.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=2f143a7db40cfb9b846fd80a6dd439635d7497069b1db2bc8e88f2c0c20aea3a)

### 9\. Multi task !

Add a way to move on several directions and rotate in the same time. Basically in this part you’ll have to handle multiple events on the same frame.

For example, if the keys to move are `w,a,s,d`:

-   If the keys `w` and `s` are pressed in the same time, the player shouldn’t move.
-   If the keys `w` and `d` are pressed in the same time, the player should move forward and right in the same time,
-   …

### 10\. Ground textures

In this part you have to add textures on the ground and/or on the ceiling !

Example

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/87792f3b4d787bf589befb8611de67a4f04d44c0.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=48c175b42811f930d96ab11b85d0ebadd24a24f4a36a6a0846401731626b800d)

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/bc961dcd5fb040c7ba1c3d7f5c640acdc2b04a34.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=07b5597803446d6ddf098a2ee803433931014d0d52433a5313bea0c2b36eba3a)

### 11\. Weapons

Add weapons textures !

Example

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/9e1e52c573a2cfb6639b0d364d0ab59ad35ab242.gif?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=ff5148bea31f657f477e5dd4f58626565653f4549f9c21a23cf8ed411ce489a5)

### 12\. Enemies

Add some enemies !

Example from the game Wolfenstein 3D:

![](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/medias/2020/9/d24c48be8c7ee901d251f35cad5673705d4dcc70.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240221%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240221T231945Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=d17df9c864a5c8125b12797a12de88980329f507dcfeaa50074a7f50594541b3)

### 13\. Make it rain

Add rain and a possibility to stop / start the rain with a key.

### 14\. Extra option

Shadows, special lightning, etc… get creative!

Copyright © 2024 ALX, All rights reserved.

×

#### Markdown Guide

#### Emphasis

```
**<strong>bold</strong>**
*<em>italics</em>*
~~<strike>strikethrough</strike>~~
```

#### Headers

```
# Big header
## Medium header
### Small header
#### Tiny header
```

#### Lists

```
* Generic list item
* Generic list item
* Generic list item

1. Numbered list item
2. Numbered list item
3. Numbered list item
```

#### Links

```
[Text to display](http://www.example.com)
```

#### Quotes

```
&gt; This is a quote.
&gt; It can span multiple lines!
```

#### Images

CSS style available: `width, height, opacity`

```
![](http://www.example.com/image.jpg)
![](http://www.example.com/image.jpg | width: 200px)
![](http://www.example.com/image.jpg | height: 124px | width: 80px | opacity: 0.6)
```

#### Tables

```
| Column 1 | Column 2 | Column 3 |
| -------- | -------- | -------- |
| John     | Doe      | Male     |
| Mary     | Smith    | Female   |

<em>Or without aligning the columns...</em>

| Column 1 | Column 2 | Column 3 |
| -------- | -------- | -------- |
| John | Doe | Male |
| Mary | Smith | Female |
```

#### Displaying code

````
`var example = "hello!";`

<em>Or spanning multiple lines...</em>

```
var example = "hello!";
alert(example);
```
````

zE('webWidget', 'prefill', { email: { value: 'iriele.moses@gmail.com', readOnly: true } });<iframe data-product="web_widget" title="No content" role="presentation" tabindex="-1" allow="microphone *" aria-hidden="true" src="about:blank" style="width: 0px; height: 0px; border: 0px; position: absolute; top: -9999px;"></iframe><iframe id="nr-ext-rsicon" style="position: absolute; display: none; width: 50px; height: 50px; z-index: 2147483647; border-style: none; background: transparent; top: 459px; left: 672px;"></iframe>

<iframe title="Opens a widget where you can find more information" id="launcher" tabindex="0" style="color-scheme: light; width: 108px; height: 50px; padding: 0px; margin: 10px 20px; position: fixed; bottom: 0px; overflow: visible; opacity: 1; border: 0px; z-index: 999998; transition-duration: 250ms; transition-timing-function: cubic-bezier(0.645, 0.045, 0.355, 1); transition-property: opacity, top, bottom; right: 0px;"></iframe>
