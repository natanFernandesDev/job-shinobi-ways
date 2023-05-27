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

end