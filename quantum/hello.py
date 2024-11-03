from qiskit import QuantumCircuit
import matplotlib.pyplot as plt  # Import for rendering

qc = QuantumCircuit(2)
qc.h(0)
qc.cx(0, 1)

qc.draw(output='mpl')  # This should now work if all dependencies are in place
