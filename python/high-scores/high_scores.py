def latest(scores):
    return scores[-1]


def personal_best(scores):
    best = scores[0]
    for i in range(1, len(scores)):
        if scores[i] > best:
            best = scores[i]
    return best


def personal_top_three(scores):
    top_three_scores = []

    for i in range(3):
        if len(scores) > 0:
            best = personal_best(scores)
            top_three_scores.append(best)
            scores.remove(best)

    return top_three_scores
