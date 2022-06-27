Clear-Host

function build {
    if (Test-Path -Path "build") {

    } else {
        New-Item -Path "build" -ItemType Directory
    }
    Push-Location "build"
    cmake -G"Ninja" -DCMAKE_EXPORT_COMPILE_COMMANDS=True ..
    cmake --build .
    if (Test-Path -Path "compile_commands.json"){
        Move-Item -Path ".\compile_commands.json" -Destination ".." -Force
    }
    Pop-Location
}

function run {
    build
    if ((Test-Path -Path "build/game") -or (Test-Path -Path "./build/game.exe")){
        ./build/game
    } else {
        Write-Output "Some compile error"
    }
}

function clear_project {
    Remove-Item -Path "build" -Force -Recurse
}

if ($args[0]) {
    switch ($args[0]) {
        "build" { build}
        "run" { run}
        "clear" { clear_project}
        default {
            Write-Output "option $args[0] not valid"
        }
    }
} else { Write-Output "Specify an option" }