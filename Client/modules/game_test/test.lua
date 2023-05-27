function init()
    connect(g_game, {
        onTest = test,
    })
end

function terminate()
    disconnect(g_game, {
        onTest = test,
    })
end

function test()
    local player = g_game.getLocalPlayer()
    print(player:getName())
end