template <class T>

bool addFirstElement(treap<T>*& treapEl, QString firstWindow, QString secondWindow) {
	int i = 0;
	int flagOne = 0, flagTwo = 0;
	int sch = 1;
	bool isCorrect = false;
	if (firstWindow[i] == '-') {
		sch = -1;
		++i;
	}
	while (firstWindow[i].toLatin1() <= 57 && firstWindow[i].toLatin1() >= 48) {
		flagOne += firstWindow[i].toLatin1() - 48;
		flagOne *= 10;
		isCorrect = true;
		++i;
	}
	if (!isCorrect || i != firstWindow.length()) return false;
	flagOne /= sch * 10;
	i = 0;
	sch = 1;
	isCorrect = false;
	if (secondWindow[i] == '-') {
		sch = -1;
		++i;
	}
	while (secondWindow[i].toLatin1() <= 57 && secondWindow[i].toLatin1() >= 48) {
		flagTwo += secondWindow[i].toLatin1() - 48;
		flagTwo *= 10;
		isCorrect = true;
		++i;
	}
	if (!isCorrect || i != secondWindow.length()) return false;
	flagTwo /= sch * 10;
	treapEl->key = flagOne;
	treapEl->priority = flagTwo;
	return true;
}

template <class T>

QString addOrDelIntTreapElLine(treap<T>*& treapEl, QString sourceString, bool isAdd) {
	int i = 0;
	int k = 0;
	QString result = "";
	QVector<int> newString(1);
	QVector< QVector<int> >addTreapEl;
	while (i < sourceString.length()) {
		if (sourceString[i] != '(') {
			return "Incorrect input data";
		}
		else {
			++i;
			int sch = 1;
			int flag = 0;
			bool isCorrect = false;
			if (sourceString[i] == '-') {
				sch = -1;
				++i;
			}
			while (sourceString[i].toLatin1() <= 57 && sourceString[i].toLatin1() >= 48) {
				flag += sourceString[i].toLatin1() - 48;
				flag *= 10;
				isCorrect = true;
				++i;
			}
			if (!isCorrect) return "Incorrect input data";
			newString[0] = sch * flag / 10;
			addTreapEl.push_back(newString);
			if (sourceString[i] != ',') {
				return "Incorrect input data";
			}
			else {
				++i;
				int sch = 1;
				int flag = 0;
				bool isCorrect = false;
				if (sourceString[i] == '-') {
					sch = -1;
					++i;
				}
				while (sourceString[i].toLatin1() <= 57 && sourceString[i].toLatin1() >= 48) {
					flag += sourceString[i].toLatin1() - 48;
					flag *= 10;
					isCorrect = true;
					++i;
				}
				if (!isCorrect) return "Incorrect input data";
				addTreapEl[k].push_back(sch * flag / 10);
				++k;
				++i;
			}
		}
	}
	if (isAdd) {
		treap<T>* newTreapEl = new treap<T>[addTreapEl.size()];
		for (int k = 0; k < addTreapEl.size(); ++k) {
			bool res = false;
			newTreapEl[k].key = addTreapEl[k][0];
			newTreapEl[k].priority = addTreapEl[k][1];
			isExistInTreapXorY(treapEl, newTreapEl + k, res);
			result += "Element ";
			result += "(" + QString::number(newTreapEl[k].key) + "," + QString::number(newTreapEl[k].priority) + ")";
			if (isExistInTreap(treapEl, newTreapEl + k)) {
				result += " exist/";
			}
			else {
				if (res) {
					result += " uncorrect/x or y eq/";
					delete (newTreapEl + k);
				}
				else {
					result += " not exists/ add /";
					insertElInTreap(treapEl, newTreapEl + k);
				}
			}
			result += "\n";
		}
		return result;
	}
	else {
		treap<T>* newTreapEl = new treap<T>[addTreapEl.size()];
		for (int k = 0; k < addTreapEl.size(); ++k) {
			if ((treapEl->left == NULL) && (treapEl->right == NULL)) {
				result += ("it last element/ if u del el u del tree / \n");
			}
			else {
				newTreapEl[k].key = addTreapEl[k][0];
				newTreapEl[k].priority = addTreapEl[k][1];
				result += "Element ";
				result += "(" + QString::number(newTreapEl[k].key) + "," + QString::number(newTreapEl[k].priority) + ")";
				if (isExistInTreap(treapEl, newTreapEl + k)) {
					result += " exist/ delete/";
					deleteTreapEl(treapEl, (newTreapEl + k)->key);
				}
				else {
					result += " not exists/";
				}
				result += "\n";
			}
		}
		delete[] newTreapEl;
		return result;
	}
}