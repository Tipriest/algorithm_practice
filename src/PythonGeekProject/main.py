import sys, argparse
import numpy as np
import random
import matplotlib.pyplot as plt
import matplotlib.animation as animation

ON = 255
OFF = 0
vals = [ON, OFF]
def randomGrid(N):
    """returns a grid of N*N random values"""
    p1 = random.random()
    return np.random.choice(vals, N*N, p = [p1, 1-p1]).reshape(N, N)

def addGlider(i, j, grid):
    """add a glider with top-left cell at (i, j)"""
    glider = np.array(
        [0, 0, 255],
        [255, 0, 255],
        [0, 255, 255]
    )
    grid[i:i+3, j:j+3] = glider

def update(frameNum, img, grid, N):
    newGrid = grid.copy()
    for i in range(N):
        for j in range(N):
            total = int((
                grid[(i-1)%N, (j-1)%N] + grid[(i-1)%N, (j)%N] + grid[(i-1)%N, (j+1)%N] + 
                grid[(i-0)%N, (j-1)%N] + grid[(i-0)%N, (j)%N] + grid[(i-0)%N, (j+1)%N] + 
                grid[(i+1)%N, (j+1)%N] + grid[(i+1)%N, (j)%N] + grid[(i+1)%N, (j+1)%N]
            )/255)
            if grid[i, j] == ON:
                if (total<2) or (total>3):
                    newGrid[i, j] = OFF
            else:
                if total == 3:
                    newGrid[i, j] = ON
    img.set_data(newGrid)
    grid[:] = newGrid[:]
    return img

def main():
    parser = argparse.ArgumentParser(
        description="Run Conway's Games of Life Simulation"
    )
    parser.add_argument('--grid-size', dest='N',          required=False)
    parser.add_argument('--mov-file',  dest='movfile',    required=False)
    parser.add_argument('--interval',  dest='interval',   required=False)
    parser.add_argument('--glider',    dest='store_true', required=False)
    parser.add_argument('--gosper',    dest='store_true', required=False)
    args = parser.parse_args()
    
    N = 200
    if args.N and int(args.N) > 8:
        N = args.N
    updateinterval = 500
    if args.interval:
        updateinterval = args.interval
    grid = np.array([])
    # if args.glider:
    #     grid = np.zeros(N*N).reshape(N, N)
    #     addGlider(1, 1, grid)
    # else:
    grid = randomGrid(N)
    fig, ax = plt.subplots()
    # img = ax.imshow(grid, interpolation='nearest', cmap='binary', vmin=0, vmax=255)
    img = ax.imshow(grid, interpolation='nearest', cmap='binary')
    ani = animation.FuncAnimation(  fig, update, fargs = (img, grid, N, ), 
                                    frames=10,
                                    interval = updateinterval,
                                    save_count=50)
    if args.movfile:
        ani.save(args.movfile, fps = 30, extra_args=['-vcodec', 'libx264'])
    plt.show()
    
if __name__ == "__main__":
    main()