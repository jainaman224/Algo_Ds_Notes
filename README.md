# Welcome to Algorithm and Data Structures Notes

Our open source community is focussed on understand concepts and whenever someone is trapped, they can see one way to code. So, we are making an repository having implementation in as many languages as we can.

## Steps to follow

### 1. Fork it :fork_and_knife:

You can get your own fork/copy of [Algo_Ds_Notes](https://github.com/jainaman224/Algo_Ds_Notes) by using the <a href="https://github.com/jainaman224/Algo_Ds_Notes/new/master?readme=1#fork-destination-box"><kbd><b>Fork</b></kbd></a> button or clicking [this](https://github.com/jainaman224/Algo_Ds_Notes/new/master?readme=1#fork-destination-box).

 [![Fork Button](https://help.github.com/assets/images/help/repository/fork_button.jpg)](https://github.com/jainaman224/Algo_Ds_Notes)

### 2. Clone it :busts_in_silhouette:

Once you have forked the `Algo_Ds_Notes` repository in Github, Create a new folder first using om linux and Mac

```sh
# This will create a folder named Name
$ mkdir Name
```

Move to this folder for all other commands.

Now, You need to clone (download) it to local machine using

```sh
$ git clone https://github.com/Your_Username/Algo_Ds_Notes.git
```

> This makes a local copy of repository in your machine.

### 3. Set it up

Run the following commands to see that *your local copy* has a reference to *your forked remote repository* in Github :octocat:

```sh
$ git remote -v
origin  https://github.com/Your_Username/Algo_Ds_Notes.git (fetch)
origin  https://github.com/Your_Username/Algo_Ds_Notes.git (push)
```

Now, lets add a reference to the original [Algo_Ds_Notes](https://github.com/jainaman224/Algo_Ds_Notes) repository using

```sh
$ git remote add upstream https://github.com/jainaman224/Algo_Ds_Notes.git
```

> This adds a new remote named ***upstream***.

See the changes using

```sh
$ git remote -v
origin    https://github.com/Your_Username/Algo_Ds_Notes.git (fetch)
origin    https://github.com/Your_Username/Algo_Ds_Notes.git (push)
upstream  https://github.com/jainaman224/Algo_Ds_Notes.git (fetch)
upstream  https://github.com/jainaman224/Algo_Ds_Notes.git (push)
```

### 4. **Sync it** :recycle:

Always keep your local copy of repository updated with the original repository.
Before making any changes and/or in an appropriate interval, run the following commands *carefully* to update your local repository.

```sh
# Fetch all remote repositories and delete any deleted remote branches
$ git fetch --all --prune

# Switch to `master` branch
$ git checkout master

# Reset local `master` branch to match `upstream` repository's `master` branch
$ git reset --hard upstream/master

# Push changes to your forked `Algo_Ds_Notes` repo
$ git push origin master
```

### 5. Ready Steady Go... :turtle: :rabbit2:

Once you have completed these steps, you are ready to start contributing by checking our `Help Wanted` Issues and creating [pull requests](https://github.com/jainaman224/Algo_Ds_Notes/pulls).

### 6. Create a new branch

Whenever you are going to make contribution. Please create seperate branch using command and create your master branch clean (i.e. synced with remote branch)

```sh
# It will create a new branch with name Branch_Name and switch to branch Folder_Name
$ git checkout -b Folder_Name
```

Create a seperate branch for change in different folder and try to use same name of branch as of folder.

To switch to desired branch

```sh
# To switch from one folder to other
$ git checkout Folder_Name
```

To add the changes to the branch. Use

```sh
# To add all files to branch Folder_Name
$ git add .
```

Type in a message relevant for the code reveiwer using

```sh
# This message get associated with all files you have changed
$ git commit -m 'relevant message'
```

Finally Push the work to your remote repository using

```sh
# To push your work to your remote repository
$ git push -u origin Folder_Name
```

Finally go to your repo in browser and click on compare and pull requests.
Then add a title and Description to your pull request.

## Help Contributing Guides

We love to have new codes in different languages not implemnted yet or betterment in existing codes.

First discuss with us by creating new issue.

_**Happy Contributing**_ :smiley:
