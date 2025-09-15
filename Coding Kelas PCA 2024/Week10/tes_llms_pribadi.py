import numpy as np

# Data
text = "hello world"
chars = list(set(text))
char_to_idx = {ch: i for i, ch in enumerate(chars)}
idx_to_char = {i: ch for i, ch in enumerate(chars)}
vocab_size = len(chars)

# Hyperparameters
hidden_size = 100
seq_length = len(text) - 1
learning_rate = 0.1

# Model parameters
Wxh = np.random.randn(hidden_size, vocab_size) * 0.01
Whh = np.random.randn(hidden_size, hidden_size) * 0.01
Why = np.random.randn(vocab_size, hidden_size) * 0.01
bh = np.zeros((hidden_size, 1))
by = np.zeros((vocab_size, 1))

# Utility functions
def softmax(x):
    e_x = np.exp(x - np.max(x))
    return e_x / e_x.sum(axis=0)

def forward_pass(inputs, h_prev):
    xs, hs, ys, ps = {}, {}, {}, {}
    hs[-1] = np.copy(h_prev)
    loss = 0

    for t in range(seq_length):
        xs[t] = np.zeros((vocab_size, 1))
        xs[t][inputs[t]] = 1
        hs[t] = np.tanh(np.dot(Wxh, xs[t]) + np.dot(Whh, hs[t - 1]) + bh)
        ys[t] = np.dot(Why, hs[t]) + by
        ps[t] = softmax(ys[t])
        loss += -np.log(ps[t][inputs[t], 0])

    return xs, hs, ys, ps, loss

# Training
for epoch in range(1000):
    h_prev = np.zeros((hidden_size, 1))
    inputs = [char_to_idx[ch] for ch in text[:-1]]
    targets = [char_to_idx[ch] for ch in text[1:]]

    # Forward pass
    xs, hs, ys, ps, loss = forward_pass(inputs, h_prev)

    # Backward pass
    dWxh, dWhh, dWhy = np.zeros_like(Wxh), np.zeros_like(Whh), np.zeros_like(Why)
    dbh, dby = np.zeros_like(bh), np.zeros_like(by)
    dh_next = np.zeros_like(hs[0])

    for t in reversed(range(seq_length)):
        dy = np.copy(ps[t])
        dy[targets[t]] -= 1
        dWhy += np.dot(dy, hs[t].T)
        dby += dy
        dh = np.dot(Why.T, dy) + dh_next
        dhraw = (1 - hs[t] * hs[t]) * dh
        dbh += dhraw
        dWxh += np.dot(dhraw, xs[t].T)
        dWhh += np.dot(dhraw, hs[t - 1].T)
        dh_next = np.dot(Whh.T, dhraw)

    # Update parameters
    for param, dparam in zip([Wxh, Whh, Why, bh, by], [dWxh, dWhh, dWhy, dbh, dby]):
        param -= learning_rate * dparam

    if epoch % 100 == 0:
        print(f"Epoch {epoch}, Loss: {loss}")

# Generating text
h = np.zeros((hidden_size, 1))
seed_idx = char_to_idx['l']
generated_text = [seed_idx]

for _ in range(50):
    x = np.zeros((vocab_size, 1))
    x[seed_idx] = 1
    h = np.tanh(np.dot(Wxh, x) + np.dot(Whh, h) + bh)
    y = np.dot(Why, h) + by
    p = softmax(y)
    seed_idx = np.random.choice(range(vocab_size), p=p.ravel())
    generated_text.append(seed_idx)

generated_text = ''.join(idx_to_char[idx] for idx in generated_text)
print(f"\nGenerated Text:\n{generated_text}")
