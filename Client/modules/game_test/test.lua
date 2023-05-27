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

function showPaperdoll()
    local paperdoll = g_game.getLocalPlayer():getPaperdoll()
    for key, value in pairs(paperdoll) do
        print(key.." : "..tostring(value))
    end
end

function setPaperdoll(key, value)
    local paperdoll = g_game.getLocalPlayer():getPaperdoll()

    for key,_ in pairs(paperdoll) do
        if key ~= key then
            return false
        end
    end

    paperdoll[key] = value
    g_game.getLocalPlayer():setPaperdoll(paperdoll)
    return true
end

function test()
    showPaperdoll()
end