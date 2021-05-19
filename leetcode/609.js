/**
 * @param {string[]} paths
 * @return {string[][]}
 */
var findDuplicate = function(paths) {
    const map = {}
    paths.forEach(path => {
        const sp = path.split(' ')    
        const dir = sp[0]
        for (let i = 1; i < sp.length; i++) {
            const spp = sp[i].split('(')
            const content = spp[1].substring(0, spp[1].length - 1)
            
            if (Array.isArray(map[content])) {
                map[content].push(dir + '/' + spp[0])   
            } else {
                map[content] = [dir + '/' + spp[0]]
            }
        }
    })
    return Object.values(map).filter(p => p.length > 1)
};
